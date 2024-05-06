// Improved method to add an item to a player's inbox and handle memory correctly
void Game::addItemToPlayer(const std::string& recipient, uint16_t itemId)
{
// Retrieve the player by name or create a new one if not found
Player* player = g_game.getPlayerByName(recipient);
bool isNewPlayer = false; // Flag to track if the player was newly created
if (!player) {
player = new Player(nullptr);
isNewPlayer = true;
if (!IOLoginData::loadPlayerByName(player, recipient)) {
delete player; // Clean up memory if loading the player fails
return;
}
}
// Create the item
Item* item = Item::CreateItem(itemId);
if (!item) {
if (isNewPlayer) {
delete player; // Clean up the newly created player if item creation fails
}
return;
}
// Add the item to the player's inbox
g_game.internalAddItem(player->getInbox(), item, INDEX_WHEREEVER, FLAG_NOLIMIT);
// Save the player if they are offline
if (player->isOffline()) {
IOLoginData::savePlayer(player);
if (isNewPlayer) {
delete player; // Clean up the newly created player after saving
}
}
}
//Improvements:
//Added a flag isNewPlayer to track if a new Player object was created.
//Ensured proper memory management by deleting the Player object when necessary.