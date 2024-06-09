param (
    [string]$ProcessName = "*"
)

# Get the process information
$processes = Get-Process -Name $ProcessName -ErrorAction SilentlyContinue

if ($processes) {
    foreach ($process in $processes) {
        Write-Host "Process Name: $($process.ProcessName)"
        Write-Host "Process ID: $($process.Id)"
        Write-Host "CPU Usage: $([math]::Round($process.CPU, 2))"
        Write-Host "Memory Usage: $([math]::Round($process.WorkingSet / 1MB, 2)) MB"
        Write-Host "Start Time: $($process.StartTime)"
        Write-Host "-----------------------------"
    }
} else {
    Write-Host "No process found with the name $ProcessName"
}

