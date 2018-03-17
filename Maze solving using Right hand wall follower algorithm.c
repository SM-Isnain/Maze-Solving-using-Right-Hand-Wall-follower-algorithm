
extern const int UP;
extern const int DOWN;
extern const int LEFT;
extern const int RIGHT;

struct maze;

// read_maze() reads in a maze from input and returns a pointer 
//   to a new maze structure with the initial position 'S'tart
// effects:  if the maze is invalid, exits the program
struct maze *read_maze(void);

// is_wall(m, direction) determines if there is a wall in the
//   given direction in maze m (based on the current position)
// requires: direction is one of: UP, DOWN, LEFT, RIGHT
bool is_wall(const struct maze *m, int direction);

// moves(m, direction) moves in the given direction in maze m
//   (based on the current position) and prints the direction (U/D/L/R).
//   If the 'E'xit is reached, prints E and then exits the program
// requires: direction is one of: UP, DOWN, LEFT, RIGHT
// effects: modifies the maze *m (to store the new position)
//          displays output
//          if attempting to move through a wall, exits the program
void move(struct maze *m, int direction);

// turn(nd,pd) takes in pd which represents direction currently facing
// and changes pd to be nd which is the new direction
// requires: pd is not NULL
void turn (int nd, int* pd) {
  *pd = nd;
}

// actright(a) takes in a constant a representing
// direction and returns the direction that is to the right
// of this direction
int actright(int a) {
  if (a==DOWN) {
    return LEFT;
  } else if (a==UP) {
    return RIGHT;
  } else if (a==LEFT) {
    return UP;
  } else {
    return DOWN;
  }
}

// actleft(a) takes in a constant a representing
// direction and returns the direction that is to the left
// of this direction
int actleft(int b) {
  if (b==DOWN) {
    return RIGHT;
  } else if (b==UP) {
    return LEFT;
  } else if (b==LEFT) {
    return DOWN;
  } else {
    return UP;
  }
}

// solvemaze takes in a maze as ASCII characters
// from input and prints the route to be taken
// to exit the maze using Right Hand Wall follower algorithm
// as a series of D,L,R,U to represent down,left,right
// and up respectively
void solvemaze (void) {
  int sd = DOWN;
  int* dir = &sd;
  struct maze *a = read_maze();
  while (1) {
    if (is_wall(a,actright(*dir))) {
      while (is_wall(a,*dir)) {
        turn(actleft(*dir),dir);
      }
      move(a,*dir);
    } else {
      turn(actright(*dir),dir);
      move(a,*dir);
    }
  }
}
      

int main(void) {
  solvemaze();
}
