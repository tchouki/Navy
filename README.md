# Navy
Epitech PSU Tek1

## Usage

```
$> ./navy -h
USAGE
	./navy [first_player_pid] navy_positions
DESCRIPTION
	first_player_pid: only for the 2nd player. pid of the first player.
	navy_positions: file representing the positions of the ships.
```
## Example

### First Player

```
my_pid: 28749
waiting for enemy connection...

enemy connected

my positions:
 |A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 3 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: C2
C2: missed

waiting for enemy's attack..
E4: hit

my positions:
 |A B C D E F G H
-+---------------
1|. . 2 . . . . .
2|. . 2 . . . . .
3|. . . . . . . .
4|. . . 3 x 3 . .
5|. 4 . . . . . .
6|. 4 . . . . . .
7|. 4 . 5 5 5 5 5
8|. 4 . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . o . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack:
[...]
```

### Second Player

```
my_pid: 28825
successfully connected

my positions:
 |A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . . . . . . 3
3|. . . . . . . 3
4|. . 2 2 . . . .
5|. . . . . . . .
6|. . . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy's attack...
C2: missed

my positions:
 |A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|. . o . . . . 3
3|. . . . . . . 3
4|. . 2 2 . . . .
5|. . . . . . . .
6|. . . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. . . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

attack: E4
E4: hit

waiting for enemy's attack...
[...]
```

## Bonus
Create a navy in Ncurses

### Screenshot
<img width="146" alt="navy" src="https://user-images.githubusercontent.com/33022684/55513619-715bb800-5666-11e9-8606-4f64553cd180.png">
