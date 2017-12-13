
### Esrock

Currently I'm working on an Ubuntu 16.04 workstation, with the following resources:
	* SFML 2.3.2
	* g++ 5.4.0 (No reason not to update, really)
	* Vim 7.4
	* make 4.1

With those resources, you should be able to compile this project.
SFML is supposed to be cross-compat w/ Linux, Windows, and Mac. I anticipate networking will be prolematic to synchronize between those, butthe library should do the graphical heavy work for us.
We're probably going with a server-client architecture, since it's what I know. Feel free to decide otherwise if you know what you're doing. As of right now, I'm looking at a C++ backend, but Go is interesting too.

All art should be in PNG format. We're aiming for a 1080p experience, but it should be scalable downwards.
SFML is supposedly able to scale things down for us, so we might not need multiple resolutions like they do for native Android dev. But we should be ready for that.

Hopefully someone is able to compile this. I'm not sure how to target windows yet, but that's important too.

Cheers!
