# Write your MySQL query statement below
SELECT x.user_id, IFNULL(ROUND(SUM(y.action='confirmed')/COUNT(*),2),0.00)
AS confirmation_rate FROM Signups AS x LEFT JOIN Confirmations AS y
ON x.user_id=y.user_id GROUP BY x.user_id;
