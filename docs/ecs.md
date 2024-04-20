# Intro

## Entity Manager

So this guy just tracks all the active entities and it keeps all available ids that entities can have.

When you create a new entity we get the top id on our available id queue and add it to our available entity signitures the we track how many entities we have live.

When we destroy the entity we just just put back the id on queue and revert the signature and count. 

## Resources

- [A SIMPLE ENTITY COMPONENT SYSTEM (ECS) [C++]](https://austinmorlan.com/posts/entity_component_system/)

## Component Array
This a custom data type to hold the relationship between the entity and its components. We have an array of all the components, we have two arrays one that holds a mapping between between the entities and the components and an array of the Index to entities.
When we delete an entity we remove the entity from the array and move the last element from the array to the delete position, this will make sure that our data is always packed. We also update the reference indices