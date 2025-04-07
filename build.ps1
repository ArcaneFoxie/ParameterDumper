# Create build directory if it doesn't exist
if (-not (Test-Path -Path "build")) {
    Write-Host "Creating build directory..."
    New-Item -ItemType Directory -Path "build" | Out-Null
}

# Navigate to build directory
Set-Location -Path "build"

# Generate build files with CMake
Write-Host "Generating build files with CMake..."
cmake ..

# Build the project
Write-Host "Building the project..."
cmake --build . --config Release

# Check if build was successful
if ($LASTEXITCODE -eq 0) {
    Write-Host "`nBuild completed successfully!" -ForegroundColor Green
    Write-Host "The executable is located at: $(Get-Location)\Release\param_dumper.exe" -ForegroundColor Cyan
} else {
    Write-Host "`nBuild failed!" -ForegroundColor Red
    exit 1
}

# Return to original directory
Set-Location .. 