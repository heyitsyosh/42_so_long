<h1 align="center">
	so_long
</h1>

*<p align="center">This project is a small 2D game with minilibx.<br>
You'll learn about textures, sprites and tiles.</p>*

## Score: 125/100🎉

## Description:
Use `WASD` keys to move the player.  
`Esc` closes the game.  
The objective is to collect all collectibles and reach the exit.   
In bonus implementation, enemy patrol snakes are spawned randomly.

## Requirements:
To confirm that requirements are met, use the command `xeyes`. 
#### MacOS:
⚠️ You must comment out `mlx_destroy_display()` from code.  
*(Jump to location: [mandatory](https://github.com/heyitsyosh/42_so_long/blob/1b236d58b1c7453c179d63c15f88d920272e5c5d/so_long/mandatory/close_game.c#L47), 
[bonus](https://github.com/heyitsyosh/42_so_long/blob/1b236d58b1c7453c179d63c15f88d920272e5c5d/so_long/bonus/close_game_bonus.c#L68))*
```bash
brew update && brew upgrade && brew install Xquartz
```
#### Linux:
```bash
sudo apt update && sudo apt upgrade
sudo apt install xorg libxext-dev libbsd-dev
```
#### WSL:
First, fulfill Linux requirements as specified above.  
Then install and launch `VcXsrv` or `Xming`.  
Keep configuration settings default *(multiple windows, start no client, ✔ no access control)*.  
Set additional parameters to `-ac -nowgl`.  
Always launch before executing the game.

## Set-up/Compilation:
Clone repo with `--recursive` flag, `cd` into directory, then use any Makefile command.  
```
git clone --recursive https://github.com/heyitsyosh/42_so_long.git
cd 42_so_long && cd so_long
```  

#### Makefile Commands:
```C
make        //compile executable (./so_long)
make bonus  //compile executable (./so_long) with enemies
make clean  //delete .o
make fclean //delete .o and executable
make re     //delete .o and executable, recompile 
```

## Usage:  
```Java
./so_long <path_to_map>
//Example:
./so_long ./maps/map3.ber
```

## Map syntax:
Map must be rectangular.  
Map must be surrounded by walls.  
Map must be playable (player can reach all collectibles and the exit).

| Char | Interpretation |
| --- | --- |
| 0 | empty space |
| 1 | wall |
| C | collectible |
| E | map exit |
| P | player’s starting position |
