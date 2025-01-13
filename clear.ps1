Get-ChildItem -Recurse -File | Where { -not $_.extension } | Remove-Item
Remove-Item -Recurse * -Include *.exe
Remove-Item -Recurse * -Include *._*
Remove-Item -Recurse * -Include *.o