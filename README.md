# Ft_GKrellM: System Monitor

This project was the last Rush of CPP Piscine in 42 Silicon Valley. Over the weekend, we had to implement a simple analogue of the GKrellM tool.

The system monitor can display information about the following modules in real time:

* Hostname/username module
* OS info module
* Date/time module
* CPU module
* RAM module
* Network module
* Disks module

## How to use?

1. Install SFML

     `brew install sfml`

2. Build

     `make`

3. Configure

     `Set + for necessary modules at`*`config`*`file`

4. Launch

     `LD_LIBRARY_PATH=~/.brew/Cellar/sfml/2.5.1/lib ./ft_gkrellm [-tg]`

![alt text](https://github.com/kdenisova/Screenshots/blob/master/gui_mode.jpeg "Logo Title Text 1") ![alt text](https://github.com/kdenisova/Screenshots/blob/master/text_mode.jpeg)
