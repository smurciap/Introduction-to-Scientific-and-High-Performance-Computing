set term pdf
set output "workshop.pdf"
set xlabel "Sample value"
set ylabel "Probability Density Function (PDF)"
plot 'seed_1.txt' u 1:2 w lp pt 3, 'seed_2.txt' u 1:2 w lp pt 2, 'seed_5.txt' u 1:2 w lp pt 1