fig.git: %.dat
	python plot.py 

%.dat: sol.x
	./sol.x

sol.x: sol.cpp
	c++ sol.cpp -o sol.x

clean:
	rm -rf *.x *.dat