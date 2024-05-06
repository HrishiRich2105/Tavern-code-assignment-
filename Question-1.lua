-- Improved function to release storage when a player logs out
local function releaseStorage(player)
-- Set the storage value to -1 to indicate it's released
player:setStorageValue(1000, -1)
end
function onLogout(player)
-- Check if the storage value is set to 1
if player:getStorageValue(1000) == 1 then
-- Schedule the releaseStorage function to run after 1 second (1000 milliseconds)
addEvent(releaseStorage, 1000, player)
end
-- Always return true to allow logout
return true
end