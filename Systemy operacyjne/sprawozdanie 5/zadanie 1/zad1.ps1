Param (
[string]$dir,
[string]$count
)

New-Item -Path $dir -ItemType Directory
for ($i = 1; $i -le $count; $i++){
    New-Item -Path $dir\$i.txt -ItemType file
}