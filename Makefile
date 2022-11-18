CC=g++
# Adapt the variables below to your needs:
EXE=main
CPP= main.cpp biberon.cpp liste.cpp baby.cpp window.cpp text.cpp image.cpp Functions.cpp
HPP= baby.hpp biberon.hpp liste.hpp	json.hpp window.hpp text.hpp image.hpp Functions.hpp


# see https://sqlite.org/howtocompile.html. I added one option to show how it's done
SQLITE3_OPTIONS = -DSQLITE_ENABLE_JSON1

# The default is build the executable file:
default: $(EXE)

# The executable file must be rebuilt if source files changed:
$(EXE): $(C) $(CPP) $(HPP)
	$(CC) $(C) $(CPP) -lsqlite3 -lSDL2 -lSDL2_ttf -lSDL2_image -o $(EXE)

# Run of the (always up-to-date) executable:
run: $(EXE)
	./$(EXE)

# Build the UML diagram as a PNG image:
uml/classes.png: $(HPP)
	./uml/mk_uml.sh $@ $^

# Count the number of lines of code:
nblines:
	@wc -l $(CPP) $(HPP)