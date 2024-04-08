<h1 align="center">
	so_long
</h1>

*<p align="center">This project is a small 2D game with minilibx.<br>
You'll learn about textures, sprites and tiles.</p>*

## Description:
Use `WASD` keys to move the player.  
`Esc` closes the game.  
The objective is to collect all collectibles and reach the exit.   
Be careful! You lose if you bump into an enemy patrol snake.

## Requirements:
To confirm that requirements are met, use the command `xeyes`.  
#### MacOS:
⚠️ You must comment out [`mlx_destroy_display()`](https://github.com/heyitsyosh/42_so_long/blob/453383613984af318a251c923aea279e766b842f/so_long/srcs/close_game.c#L68) from code.  
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
Then install and launch `XLaunch` or `Xming`.  
Keep configuration settings default *(multiple windows, start no client, ✔ no access control)*.  
Set additional parameters to `-ac -nowgl`.  

## Set-up/Compilation:
Clone repo, `cd` into directory, then use any Makefile command.  
```
git clone --recursive https://github.com/heyitsyosh/42_so_long.git
cd 42_so_long && cd so_long
```  

#### Makefile Commands:
```Java
make        //compile executable (./so_long)
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
