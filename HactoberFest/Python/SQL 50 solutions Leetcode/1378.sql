
select eu.unique_id, e.name

from EmployeeUNI eu

right join Employees e

on eu.id=e.id

