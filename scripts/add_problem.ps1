[Console]::InputEncoding=[Text.Encoding]::UTF8
[Console]::OutputEncoding=[Text.Encoding]::UTF8

$root = Join-Path $PSScriptRoot ".."

$algo = Read-Host "알고리즘명 입력"
$prob = Read-Host "문제 ID 입력"
if ([string]::IsNullOrWhiteSpace($algo) -or [string]::IsNullOrWhiteSpace($prob)) {
  Write-Host "⚠ 알고리즘명/문제ID는 필수" -ForegroundColor Yellow; pause; exit
}

$dir = Join-Path $root ("cur_study\{0}\{1}" -f $algo,$prob)
if (-not (Test-Path $dir)) { New-Item -ItemType Directory -Path $dir | Out-Null }

$files = "CYSW.cpp","SSH.py","JYJ.py","C++_Opt.cpp","Python_Opt.py","README.md"
foreach($f in $files){
  $fp = Join-Path $dir $f
  if (-not (Test-Path $fp)){
    if ($f -eq "README.md"){
      @("## 사석훈","","## 지용주","","## 최이승우") | Set-Content -Encoding UTF8 $fp
    } else { New-Item -ItemType File -Path $fp | Out-Null }
  }
}
Write-Host "완료: $dir 생성." -ForegroundColor Green
pause
