$timestamps = Get-Content -Path '.\stamps.txt'
write-host $timestamps.GetType()

foreach($i in 0..$timestamps.Count) {

  ./convert.exe $timestamps[$i + 1] $timestamps[$i] 

}
