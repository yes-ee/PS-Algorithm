select count(*) as count
from ecoli_data
where !(genotype & 2) and ((genotype & (1<<2)) or (genotype & (1)))