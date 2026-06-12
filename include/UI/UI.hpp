//You MUST put the UIElements inside a parent, except the mainScreen, which is the parent of all UIElements

// do not expose SFML objects, not direct properties, define functions for everything and use them, don't change value randomly
// whereever possible explicity define which classes objects you are using, even if redundant

// Containers only act as groups, and the position property of UIElement derivative referes to the positon relative to the container
//a container doesn't automatically align elements or do any css things, only influences their position, and rotation(in the future).
// a container is also a UIElement derivative, hence it can also be a child, the parent UIElement of each UIElement should be defined.
//the container OWNS all the elemnts it draws

//setposition updates the sfml objects, the draw function ONLY draws them, write other functions to update them.