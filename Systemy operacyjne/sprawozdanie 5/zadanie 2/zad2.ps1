Param (
[string]$path,
[string]$Symbol
)
$count=0
$fil=[System.IO.File]::ReadAllText($path)
$len = $fil.Length
for ($i=0; $i -le $len; $i++){
    if ($fil[$i] -match $Symbol){
        $count++;
    }
}

$count