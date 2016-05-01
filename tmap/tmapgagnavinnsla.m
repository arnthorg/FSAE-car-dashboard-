v1 = v1';
v2=v2';
t1 = t1';
t2 = t2';
%%
volts = volts';
temp = temp';
%%
volts = volts(end:-1:1);
temp = temp(end:-1:1);
%%
tempvolt = horzcat(vertcat(v1,v2),vertcat(t1, t2));
plot(tempvolt(:,1), tempvolt(:,2))
%% ef gögn eru samfelld
tempvolt = horzcat(volts, temp);
%% breyta í ohm
R1 = 995;
Vin = 5;
for i = 1:length(volts)
    ohms(i) = volts(i)*R1/(Vin-volts(i));
end
%% skala volt í tempvolt f. 1k
R1 = 9900;
R1new = 1000;
Vin = 5;
for i = 1:length(volts)
    Rntc = tempvolt(i,1)*R1/(Vin-tempvolt(i,1));
    tempvolt(i,1) = Vin*Rntc/(R1new+Rntc);
end
%%
% output = tsmovavg(tempvolt,'s',36,1);
% plot(output(:,1), output(:,2))