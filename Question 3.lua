-- Improved function to remove a member from a player's party
function removeMemberFromParty(playerId, memberName)
-- Retrieve the player object using the playerId
local player = Player(playerId)
-- Get the party object from the player
local party = player:getParty()
-- Iterate through the party members
for k, member in pairs(party:getMembers()) do
-- Check if the current member is the one to remove
if member:getName() == memberName then
-- Remove the member from the party
party:removeMember(member)
break -- Exit the loop once the member is removed
end
end
end

-- IMPROVEMENT
-- 1. Renamed the function to removeMemberFromParty for clarity.
-- 2. Used :getName() to compare the member’s name instead of creating a new Player object.