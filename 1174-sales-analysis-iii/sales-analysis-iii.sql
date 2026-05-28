select p.product_id,p.product_name
from Product p
join Sales s
on s.product_id=p.product_id
group by p.product_id,p.product_name
having MIN(s.sale_date)>='2019-01-01'
and MAX(s.sale_date)<='2019-03-31'