cls
@echo "Starting the stressing";
@echo off
for /l %%t in (1, 1, 100) do @(
	a > in
	s < in > out
	sol < in > out2
	FC out out2
)
@echo on

rem if errorlevel 1 exit