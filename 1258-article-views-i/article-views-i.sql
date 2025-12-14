# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views WHERE author_id=viewer_id ORDER BY id ASC;
-- UNIQUE = a rule that says "no duplicates allowed in this column"
-- DISTINCT = a filter that says "show me only unique values from the results"