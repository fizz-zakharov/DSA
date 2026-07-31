SELECT x.visited_on, (
    SELECT SUM(amount) FROM (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) AS c
    WHERE c.visited_on BETWEEN y.visited_on AND x.visited_on
) AS amount,
ROUND((
    SELECT SUM(amount) FROM (
        SELECT visited_on, SUM(amount) AS amount
        FROM Customer
        GROUP BY visited_on
    ) AS c
    WHERE c.visited_on BETWEEN y.visited_on AND x.visited_on
) / 7, 2) AS average_amount
FROM (SELECT DISTINCT visited_on FROM Customer) AS x
JOIN (SELECT DISTINCT visited_on FROM Customer) AS y
ON DATEDIFF(x.visited_on, y.visited_on) = 6
GROUP BY x.visited_on, y.visited_on
ORDER BY x.visited_on;