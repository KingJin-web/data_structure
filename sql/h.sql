create trigger tri_1 
on Table_1 after insert as
print('插入了一个数据');

insert into Table_1 values(1,'a');

create trigger tri_2 
on c after insert as