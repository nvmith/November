[Console]::InputEncoding=[Text.Encoding]::UTF8
[Console]::OutputEncoding=[Text.Encoding]::UTF8

$root    = Join-Path $PSScriptRoot ".."
$readme  = Join-Path $root "README.md"
$curBase = Join-Path $root "cur_study"

# ---- 유틸
function UrlAlgo([string]$a){ return ($a -replace '&','%26') }

function Get-NextWeek([string[]]$Lines){
  $last = $Lines | Select-String -Pattern '^\|(\d+)주차\|' | Select-Object -Last 1
  if ($last) {
    $m = [regex]::Match($last.Line, '^\|(\d+)주차\|')
    if ($m.Success) { return ([int]$m.Groups[1].Value + 1).ToString() + "주차" }
  }
  return "1주차"
}

function EnsureRow([string[]]$Lines,[string]$Week,[string]$Division){
  $row = $Lines | Select-String -Pattern ('^\|'+[regex]::Escape($Week)+'\|') | Select-Object -First 1
  if ($row){ return ,$Lines }
  $newRow = "|{0}|{1}| | | |" -f $Week,$Division
  $last = $Lines | Select-String -Pattern '^\|\d+주차\|' | Select-Object -Last 1
  if ($last){
    $i0 = $last.LineNumber - 1
    $before = $Lines[0..$i0]
    $after = @()
    if ($i0+1 -le $Lines.Length-1){ $after = $Lines[($i0+1)..($Lines.Length-1)] }
    return ,(@($before + $newRow + $after))
  } else {
    $header = @("|주차|분류|문제1|문제2|문제3|","|:---:|:---:|:---:|:---:|:---:|")
    return ,(@($Lines + $header + $newRow))
  }
}

# ---- 주차 입력 (비우면 마지막+1)
$lines = Get-Content -Encoding UTF8 $readme
$weekIn = Read-Host "주차 (예: n 또는 n주차, 비우면 자동)"
if ([string]::IsNullOrWhiteSpace($weekIn)) { $week = Get-NextWeek $lines }
else { if ($weekIn -match '주차$'){ $week = $weekIn } else { $week = "$weekIn주차" } }

# ---- 타입 선택: 숫자만 (1=normal, 2=review)
$typeSel = Read-Host "타입 선택: 1.normal  2.review"
if ($typeSel -ne "1" -and $typeSel -ne "2"){
  Write-Host "⚠ 1 또는 2만 입력하세요." -ForegroundColor Yellow; pause; exit
}

if ($typeSel -eq "1") {
  # ===== NORMAL =====
  $algo = Read-Host "알고리즘명"
  if ([string]::IsNullOrWhiteSpace($algo)) { Write-Host "⚠ 알고리즘명은 필수" -ForegroundColor Yellow; pause; exit }

  $algoDir = Join-Path $curBase $algo
  if (-not (Test-Path $algoDir)) { Write-Host "⚠ 폴더 없음: $algoDir" -ForegroundColor Yellow; pause; exit }

  # 해당 알고리즘 폴더의 문제 폴더명 최신 3개 자동 선택
  $probs = Get-ChildItem -Path $algoDir -Directory | Sort-Object LastWriteTime -Descending | Select-Object -First 3
  if (-not $probs){ Write-Host "⚠ 해당 알고리즘 폴더 내 문제 폴더가 없습니다." -ForegroundColor Yellow; pause; exit }

  $division = $algo
  $lines = (EnsureRow -Lines $lines -Week $week -Division $division)

  # 행 갱신 (3칸 셋업)
  $row = $lines | Select-String -Pattern ('^\|'+[regex]::Escape($week)+'\|') | Select-Object -First 1
  $ri = $row.LineNumber - 1
  $cells = ($lines[$ri] -split '\|') | ForEach-Object { $_.Trim() }
  while ($cells.Count -lt 7) { $cells += "" }

  $cells[1] = $week
  $cells[2] = $division
  $cells[3] = "[{0}](./cur_study/{1}/{0})" -f $probs[0].Name, (UrlAlgo $algo)
  $cells[4] = if ($probs.Count -ge 2){ "[{0}](./cur_study/{1}/{0})" -f $probs[1].Name, (UrlAlgo $algo) } else { "" }
  $cells[5] = if ($probs.Count -ge 3){ "[{0}](./cur_study/{1}/{0})" -f $probs[2].Name, (UrlAlgo $algo) } else { "" }

  $lines[$ri] = "|" + ($cells[1..5] -join "|") + "|"
  [IO.File]::WriteAllText($readme, ($lines -join [Environment]::NewLine), (New-Object Text.UTF8Encoding($false)))
  Write-Host ("완료: {0} / {1} 행 삽입(자동 최신 3개)" -f $week,$division) -ForegroundColor Green
  pause
  exit
}

# ===== REVIEW =====
function FindAlgoForProb([string]$probId){
  $algos = Get-ChildItem -Path $curBase -Directory
  foreach($a in $algos){
    $p = Join-Path $a.FullName $probId
    if (Test-Path $p){ return $a.Name }
  }
  return $null
}

$in1 = Read-Host "문제1 ID"
$in2 = Read-Host "문제2 ID"
$in3 = Read-Host "문제3 ID"
$ids = @($in1,$in2,$in3) | Where-Object { -not [string]::IsNullOrWhiteSpace($_) }
if ($ids.Count -lt 1){ Write-Host "⚠ 최소 1개 이상 입력하세요." -ForegroundColor Yellow; pause; exit }

$division = "복습주간"
$lines = (EnsureRow -Lines $lines -Week $week -Division $division)

$row = $lines | Select-String -Pattern ('^\|'+[regex]::Escape($week)+'\|') | Select-Object -First 1
$ri = $row.LineNumber - 1
$cells = ($lines[$ri] -split '\|') | ForEach-Object { $_.Trim() }
while ($cells.Count -lt 7) { $cells += "" }

$outs = @("","","")
for($i=0; $i -lt [Math]::Min(3,$ids.Count); $i++){
  $probId = $ids[$i]   # <-- $PID 충돌 회피 (변수명 변경)
  $algoFor = FindAlgoForProb -probId $probId
  if ($algoFor){
    $outs[$i] = "[{0}] [{1}](./cur_study/{2}/{1})" -f $algoFor,$probId,(UrlAlgo $algoFor)
  } else {
    $outs[$i] = "[{0}] (경로없음)" -f $probId
  }
}

$cells[1] = $week
$cells[2] = "복습주간"
$cells[3] = $outs[0]
$cells[4] = $outs[1]
$cells[5] = $outs[2]
$lines[$ri] = "|" + ($cells[1..5] -join "|") + "|"

[IO.File]::WriteAllText($readme, ($lines -join [Environment]::NewLine), (New-Object Text.UTF8Encoding($false)))
Write-Host ("완료: {0} 복습주간 갱신" -f $week) -ForegroundColor Green
pause
