# https://kallanreed.com/2016/05/28/creating-an-etw-provider-step-by-step/

Write-Host "Not needed any more - src/meson.build does it for us instead"
return 0

mc.exe -um -h "..\..\include\pistache\" -r ".\" pist_winlog.man
rc.exe 'pist_winlog.rc'
link.exe  /dll /noentry /machine:x64 pist_winlog.res /OUT:'C:\Program Files\pistache_distribution\pistachelog.dll'
