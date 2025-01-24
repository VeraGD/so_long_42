# so_long_42

## 1. Project description

2D game that consists of taking the character to the exit, to do this you must first collect all the collectionables on the map.

In my case, the main character is a cow that has to get into the farm collecting all the DNA molecules on the map. In addition, a movement counter will be printed on the terminal.

The game can be played by pressing the WASD keys and using the arrow keys. Pressing the ESC key the game get closed, as well as using the “close” button in the upper right part of the window. It can also be minimized and placed behind other windows.

I use codam MLX42 as a graphic library.

Bonus part:
- Enemies are included, if you touch them you die, game over. These enemies are UFOs.
- The counter is rendered on the game screen if it is less than or equal to 99 moves, otherwise it is printed on the terminal.
- The main character evolves as he collects the DNA molecules, there are only 3 evolutions available, which will be done with the average of the collectibles on the map.

## 2. Map

The maps must be .ber files. They are text files where the game map is represented with certain characters.

Characteristics of the maps:
- They must be rectangular.
- They must be surrounded by walls.
- Can only be formed by the characters 1, 0, P, E, C (and G in the bonus)
    - 1 represents the walls of the game.
    - P is the main character, there can be only one character.
    - E is the exit, there can be only one.
    - C are the collectionables, there must be only one mini-collectionable.
    - 0 is the baackground, nothing else.
    - G are the enemies (bonus).
- The game must be playable, the exit and all the collectibles must be reachable by the character (they can't be isolated between walls).

Several examples can be found in the maps folder:
- If they start with 'e' they are maps with errors that will not be usable.
- If they start with 's' they are standard maps provided from the project statement itself.
- If they start with 'map' they are maps created by me, totally valid.
- If they start with 'mapbonus' they are specific for the bonus, with enemies.

## 3. How to play
- Clone the repository.
- Download the MLX42 library by using the comand make download_mlx inside the folder of the repository.
  
  ```ruby
  $> make download_mlx
  ```
- If you want to run the basic mode, execute the following commands inside the repository folder:
  
  ```ruby
  $> make
  $> ./so_long maps/map1.ber
  # You can put any map from the maps folder (except those beginning with e, they give error).
  ```
- If you want to execute the bonus mode, execute the following commands inside the repository folder:
  
  ```ruby
  $> make bonus
  $> ./so_long_bonus maps/mapbonus1.ber
  # You can put any map from the maps folder (except those beginning with e, they give error).
  ```
- If you want to delete the graphic library you can use the comand clear_mlx, also inside the repository folder:
  
  ```ruby
  $> make clean_mlx
  ```

  ## 4. Images of the game
  - Mandatory part.
    
  - Bonus part.
