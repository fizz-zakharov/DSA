# Write your MySQL query statement below
SELECT x.machine_id, ROUND(AVG(y.timestamp-x.timestamp),3) AS processing_time FROM
Activity AS x JOIN Activity AS y 
ON x.process_id=y.process_id AND x.machine_id=y.machine_id 
WHERE x.activity_type='start' AND y.activity_type='end'
GROUP BY x.machine_id;