# filler
## Project from Algorithms branch in school 42
### filler is the project where you need to create AI which will play versus another AI or human.

## Game rules
* 2 players in turn put randomly assigned pieces on the game board.

* The new placed piece must be attached to the rest of its parts with only one block from the whole new piece.

* The new placed piece should not touch enemy pieces.

* The new placed piece should not get out of the game board.

### Example of some possible pieces
![](https://github.com/prippa/my-projects-media/blob/main/filler/LegalDownrightBighornedsheep-size_restricted.png)

## Algorithm
In my filler bot i implement of **manhattan distance formula** to find the nearest point to the enemy.
This is the basis for my whole strategy of victory.
Put a new piece than the closer to the enemy to block his moves.

## Visualizer programme

### flags
 * **\[Plus number\]** : Delay next turn in microseconds.
 * **-d**          : Debug mode.
 * **-s**          : Epic Mortal Kombat Theme Music.
 * **-help**       : prints usage.
 ***
 
 ### Base mode.
![](https://github.com/prippa/my-projects-media/blob/main/filler/FamousDizzyGoosefish-size_restricted.gif)
***
### Debug mode. The mode where you can see next move by pressing Enter.
![](https://github.com/prippa/my-projects-media/blob/main/filler/PrestigiousWavyAmericanwirehair-size_restricted.gif)
[more info](https://github.com/prippa/filler/blob/master/filler.en.pdf)
