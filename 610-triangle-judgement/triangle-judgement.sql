SELECT x,y,z,case
WHEN x+y>z AND x+z>y AND y+z>x THEN"Yes"
else "No"
END AS Triangle
FROM Triangle;