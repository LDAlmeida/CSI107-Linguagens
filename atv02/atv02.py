from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.service import Service
from webdriver_manager.firefox import GeckoDriverManager

#Precisa do Firefox instalado, depois criar a venv de acordo com o requirements.txt.


#Abstração
class Professor:
    def __init__(self, nome, area, email):
        self.nome = nome
        self.area = area
        self.email = email
        self.ramal = None
        self.sala = None

    #Polimorfismo/Encapsulamento
    def print_professor(self):
        print(f"Nome: {self.nome}")
        print(f"Área: {self.area}")
        print(f"Email: {self.email}")
        if self.ramal:
            print(f"Ramal: {self.ramal}")
        if self.sala:
            print(f"Sala: {self.sala}")

#Herança
class DECSIProfessor(Professor):
    def __init__(self, nome, area, email):
        super().__init__(nome, area, email)

class DEENPProfessor(Professor):
    def __init__(self, nome, area, email, ramal, sala):
        super().__init__(nome, area, email)
        self.ramal = ramal
        self.sala = sala

options = webdriver.FirefoxOptions()
options.headless = True

driver = webdriver.Firefox(service=Service(GeckoDriverManager().install()))

driver.get("https://decsi.ufop.br/docentes")

elements = driver.find_elements(by=By.CSS_SELECTOR, value="#node-3229 > div > div > div > div")

lines = elements[0].text.splitlines()

professores = []

while lines:
    area = lines.pop()
    lines.pop()
    email = lines.pop()
    nome = lines.pop()

    professor = DECSIProfessor(nome=nome, area=area, email=email)
    professores.append(professor)

driver.get("https://deenp.ufop.br/corpo-docente")

table_data = driver.find_elements(by=By.CSS_SELECTOR, value='.field-item > table:nth-child(3)')

for row in table_data:
    tds = row.find_elements(By.TAG_NAME, "td")
    nome = tds[0].text
    area = tds[3].text
    ramal = tds[4].text
    sala = tds[5].text
    email = tds[6].text

    professor = DEENPProfessor(nome=nome, area=area, email=email, ramal=ramal, sala=sala)
    professores.append(professor)

area = input("Digite uma área: ")

for professor in professores:
    if area in professor.area:
        professor.print_professor()

driver.close()