# Virtual World

A student project written in C++ simulating a virtual world with different types of animals and plants nad their behaviours.

## Description
The simulation works in a turn-based manner and is presented as a 2D matrix where different types of organims occupy one field and do a certain action that is specific to their type on each round.

#### Organisms:
Each organism has three main characteristics that are crucial for the world to function:
- Initiative - declares what type of organism will make an action first
- Strength - decides which organism wins a confrontation if two are placed on the same field (doesn't apply if organims are the same species).
- Position - tells on which field in the matrix an organism is standing

There are three main types of organisms in the virtual world:
- Animals:
    - each round moves on a randomly picked,    adjacent field
    - if collided during the movement with the same species a new animal is created and placed next to the field where collision happened
- Plants:
    - there is a chance each round that a plant can replicate and place a new organism of the same species on the nearest random field
- Human:
    - there is only one human on the map
    - controlled by the user
    - has a special skill that can be used which lasts for 5 rounds

## Getting started
How to run this project:
1. Clone this repository.
2. Open `*.sln` file using Visual Studio.
3. Build and run the project.

## How to use
#### Menu:
When started user is presented with two options to choose which type of matrix he wants to use:
- traditional `1` - a preconfigured matrix is given to the user with fixed organisms arrangement
- from a file `2` - if previously saved, user can start playing with the arrangement that was noted
The game starts when the number corresponding to one of the options is entered and confirmed by pressing `ENTER`

#### Game:
While playing the user is given a number of activities to perform which are activated by pressing the presented keys:
- `ARROW UP` - moves the human one field up
- `ARROW DOWN` - moves the human one field down
- `ARROW LEFT` - moves the human one field left
- `ARROW RIGHT` - moves the human one field right
- `SPACE` - activates the humans special ability
- `ENTER` - makes a round in the simulation
- `S` - saves the state of the game to a file
- `Q` - quits the simulation

On each round made the state of the world is updated and presented to the user. In addition under the matrix there is a journal that shows information about the actions that occured during the round.
