dependency:
 	cd build && cmake .. --graphviz=graph.dot && dot -Tpng graph.dot -o graphimage.png
prepare:
	rm -rf build
	mkdir build
	cd build