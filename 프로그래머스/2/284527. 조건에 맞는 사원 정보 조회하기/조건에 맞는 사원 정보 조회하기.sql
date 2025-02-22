select sum(score) as score, emp.emp_no, emp_name, position, email
from hr_employees emp
    join hr_grade grd
    on emp.emp_no = grd.emp_no
where year = 2022
group by emp_no
order by score desc
limit 1
