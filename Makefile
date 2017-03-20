
CFLAGS = -I/usr/include -I/usr/local/include -g

LDFLAGS = -L/usr/lib -L/usr/local/lib -lglad -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -ldl -lpthread

main: main.cc
	clang++ $(CFLAGS) -o $@ $^ $(LDFLAGS)

