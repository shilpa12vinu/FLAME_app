#!/usr/bin/gnuplot -persist
set xlabel "Length"
set ylabel "u(x,t)"

set term x11 0  #Creating a new window with ID 0
plot "test0" using 1:3 w l lw 1.5 title "Analytical time step=0"
#set term x11 1 # Creating another window with ID 1
replot "test0" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=0"


set term x11 1  #Creating a new window with ID 1
plot "test100" using 1:3 w l lw 1.5 title "Analytical time step=100"
replot "test100" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=100"

set term x11 2  #Creating a new window with ID 2
plot "test500" using 1:3 w l lw 1.5 title "Analytical time step=500"
replot "test500" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=500"


set term x11 3  #Creating a new window with ID 3
plot "test1000" using 1:3 w l lw 1.5 title "Analytical time step=1000"
replot "test1000" using 1:2 w p lc rgb 'black' pt 9 title "Simulation time step=1000"


