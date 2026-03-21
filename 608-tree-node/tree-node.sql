SELECT id,case WHEN p_id IS NULL then "Root"
WHEN id IN (SELECT p_id FROM Tree) then "Inner"
else "Leaf" end as "Type"
FROM Tree;