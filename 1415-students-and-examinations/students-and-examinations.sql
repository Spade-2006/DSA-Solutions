SELECT S.student_id, S.student_name, Sub.subject_name, count(E.student_id) as attended_exams
from Students S
Cross Join Subjects Sub
Left Join Examinations E on S.student_id = E.student_id and Sub.subject_name = E.subject_name
Group by S.student_id, S.student_name, Sub.subject_name
Order by S.student_id, Sub.subject_name;