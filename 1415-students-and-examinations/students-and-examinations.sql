# Write your MySQL query statement below
SELECT x.student_id,x.student_name,y.subject_name,COUNT(z.student_id)
AS attended_exams FROM Students AS x CROSS JOIN Subjects AS y LEFT JOIN
Examinations AS z ON x.student_id=z.student_id AND y.subject_name=z.subject_name
GROUP BY x.student_id, x.student_name,y.subject_name
ORDER BY x.student_id,y.subject_name;