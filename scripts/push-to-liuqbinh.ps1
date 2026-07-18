# Push this project as a fork under LiuQBinh
# Run once after: gh auth login
#
# Usage (PowerShell, from repo root):
#   .\scripts\push-to-liuqbinh.ps1

$ErrorActionPreference = "Stop"
$env:Path = [System.Environment]::GetEnvironmentVariable("Path","Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path","User")

$Upstream = "Donchitos/Claude-Code-Game-Studios"
$Owner = "LiuQBinh"
$RepoName = "Claude-Code-Game-Studios"

Write-Host "==> Checking gh auth..."
gh auth status
$login = (gh api user --jq .login)
if ($login -ne $Owner) {
  Write-Warning "Logged in as '$login' (expected '$Owner'). Continuing with this account."
  $Owner = $login
}

Write-Host "==> Forking $Upstream (noop if already forked)..."
gh repo fork $Upstream --clone=false --remote=false 2>&1 | Out-Host

$forkUrl = "https://github.com/$Owner/$RepoName.git"
Write-Host "==> Remote origin -> $forkUrl"
if (git remote get-url origin 2>$null) {
  git remote set-url origin $forkUrl
} else {
  git remote add origin $forkUrl
}
git remote remove upstream -ErrorAction SilentlyContinue 2>$null
git remote add upstream "https://github.com/$Upstream.git" 2>$null
git remote -v

Write-Host "==> Pushing main..."
git push -u origin main

Write-Host ""
Write-Host "Done: https://github.com/$Owner/$RepoName"
