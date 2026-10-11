# Write your MySQL query statement below
SELECT ROUND(
    COUNT(DISTINCT x.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity),2
) AS fraction
FROM Activity AS x
JOIN
(
    SELECT player_id,MIN(event_date) AS first_date
    FROM Activity GROUP BY player_id
) AS y
ON x.player_id=y.player_id
AND DATEDIFF(x.event_date,y.first_date)=1;