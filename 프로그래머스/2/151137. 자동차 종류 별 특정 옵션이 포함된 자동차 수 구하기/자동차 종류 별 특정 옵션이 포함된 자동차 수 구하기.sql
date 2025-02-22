-- 코드를 입력하세요
SELECT CAR_TYPE, count(*) as cars
FROM CAR_RENTAL_COMPANY_CAR
WHERE OPTIONS LIKE '%통풍시트%' or OPTIONS LIKE '%열선시트%' or OPTIONS LIKE '%가죽시트%'
group by car_type
order by car_type asc