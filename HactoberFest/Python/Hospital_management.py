#Program for hospital management 
print("Welcome to fortis healthcare")
print("Please choose the department you want to access")
print("1)Medical billing section")
print("2)Patient database")
print("3)Pharmaceuticals")
choice=str(input("Enter your choice of department here:"))
if choice=="Medbill":
    print("Welcome to the medical billing section")
    patname=str(input("Enter the patient's name:"))
    patbill=int(input("Enter the patients treatment cost:"))
    patsalary=int(input("Enter patient's salary:"))
    if patsalary>=15000:
        print("Here's the patient's bill",patbill)
    elif patsalary<15000:
      billred=patbill/10
      revpatbill=patbill-billred
      print("Here's the revised patient's bill as per the low salary quota",revpatbill)
elif choice=="Patient database":
  print("Cardiology")
  print("Orthopaedic")
  print("Psychiatric")
  depchoice=str(input("Please choose the department you want to access:"))
  if depchoice=="Cardiology":
    cardicode=str(input("Enter patient's code:"))
    if cardicode=="1001A":
      print("Patient's name:Avinash singh")
      print("Diagnosed with:Artery blockage")
      print("Treatment type:Surgery")
      print("Case under Dr.D'souza")
    elif cardicode=="1002B":
      print("Patient's name:Anmol singh")
      print("Diagnosed with:Irregular heartbeats")
      print("Treatment type:Placing a pacemaker to regulate heartbeats")
      print("Case under Dr.Thodge")
    elif cardicode=="1003C":
      print("Patient's name:Vansh Raghav")
      print("Diagnosed with:Cardiac arrest")
      print("Treatment type:Surgery")
      print("Case under Dr.Patole")
    else:
      print("Please enter a valid code")
  elif depchoice=="Orthopaedic":
    orthocode=str(input("Enter patient's code:"))
    if orthocode=="2001A":
      print("Patient's name:Rohan kumar")
      print("Suffering from dislocated shoulder")
      print("Recommended treatment:Plastering and casting the shoulder for support")
      print("Case under Dr.Kale")
    elif orthocode=="2002B":
      print("Patient's Ishan sharma")
      print("Suffering from cranical crack")
      print("Recommended treatment:Surgery")
      print("Case under Dr.Joshi")
    elif orthocode=="2003C":
      print("Patient's Ishan sharma")
      print("Suffering from cranical crack")
      print("Recommended treatment:Surgery")
      print("Case under Dr.Joshi")
    else:
      print("Please enter a valid code")
  elif depchoice=="Physciatric":
    psychcode=str(input("Enter patient's code:"))
    if psychcode=="3001A":
      print("Patients name:Raj Thakur")
      print("Suffering from PTSD")
      print("Recommended treatment:Therapy sessions")
      print("Case under Dr.Khan")
    elif psychcode=="3002B":
      print("Patients name:Satish kumar")
      print("Suffering from Anxiety attacks")
      print("Recommended treatment:personality developement classes")
      print("Case under Dr.Bedi")
    elif psychcode=="3001A":
      print("Patients name:Rajesh sharma")
      print("Suffering from depression")
      print("Recommended treatment:Suppresant pills")
      print("Case under Dr.Shah")
    else:
      print("Please enter a valid code")
elif choice=="Pharmacy":
  genail=str(input("Please enter the generic ailment the patient is suffering from:"))
  if genail=="Fever":
    print("Crocin")
    print("Paracetomol")
    print("wet towels")
  elif genail=="Sprained knee":
    print("Volini spray")
    print("Pressure band")
  elif genail=="Migrane":
    print("Tiger Balm")
    print("Vicks vaporub")
    print("Vicks 500")
  elif genail=="Acidity":
    print("Digene")
    print("Vitamin supplements")
    print("Yakult")
  else:
    print("Given ailment not found in database")
else:
  print("Please choose one of the given departments")