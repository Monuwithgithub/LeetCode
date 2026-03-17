SELECT P.project_id , ROUND(AVG(E.experience_years),2) 
as average_years
from Project P 
join 
Employee E on 
P.Employee_id=E.employee_id
group by P.project_id
