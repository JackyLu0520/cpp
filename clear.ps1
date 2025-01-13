Get-ChildItem -Recurse -File | Where { -not $_.extension } | Remove-Item
Remove-Item -Recurse * -Include *.exe
Remove-Item -Recurse * -Include *._*