set term pdf
set output "gammafunc.pdf"
set log y
set xlabel "Sample value"
set ylabel "Gamma function"
plot 'gammafunc.txt' u 1:2 w lp pt 3