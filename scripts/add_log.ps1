[Console]::InputEncoding=[Text.Encoding]::UTF8
[Console]::OutputEncoding=[Text.Encoding]::UTF8

$root   = Join-Path $PSScriptRoot ".."
$readme = Join-Path $root "README.md"

$type = Read-Host "유형 입력 (지각/결석)"
if ($type -ne "지각" -and $type -ne "결석"){ Write-Host "⚠ 지각/결석만 허용" -ForegroundColor Yellow; pause; exit }
$name = Read-Host "이름 입력"
if ([string]::IsNullOrWhiteSpace($name)){ Write-Host "⚠ 이름 필수" -ForegroundColor Yellow; pause; exit }
$date = Read-Host "날짜 입력 (YYYY.MM.DD, 미입력 시 오늘)"
if ([string]::IsNullOrWhiteSpace($date)){ $date = (Get-Date).ToString("yyyy.MM.dd") }

$lines = Get-Content -Encoding UTF8 $readme
$hdr   = $lines | Select-String -SimpleMatch "## 지원금 내역" | Select-Object -First 1
$entry = "- {0} ({1} {2})" -f $date,$name,$type

if (-not $hdr) {
  $lines = @($lines + "## 지원금 내역" + $entry)
} else {
  $h = $hdr.LineNumber - 1
  $next = ($lines[($h+1)..($lines.Length-1)] | Select-String -Pattern '^## ' | Select-Object -First 1)
  $end = if ($next){ $h + $next.LineNumber - 2 } else { $lines.Length - 1 }
  $before = $lines[0..$end]
  $after  = @()
  if ($end + 1 -le $lines.Length - 1){ $after = $lines[($end+1)..($lines.Length-1)] }
  $lines = @($before + $entry + $after)
}
[IO.File]::WriteAllText($readme, ($lines -join [Environment]::NewLine), (New-Object Text.UTF8Encoding($false)))
Write-Host "완료: 지원금 내역 마지막 줄에 추가." -ForegroundColor Green
pause
