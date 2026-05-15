from flask import Flask

app = Flask(__name__)

@app.route('/')
def home():
    return '''
        <!DOCTYPE html>
        <html lang="pt-BR">
        <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1.0">
            <title>Currículo</title>
        </head>
        <body>
            <h1>Currículo</h1>

            <h2>Informações Pessoais</h2>
            <ul>
                <li><strong>Nome:</strong> Bernardo Ângelo</li>  
                <li><strong>Email:</strong> 12400602@aluno.cotemig.com.br</li>
                <li><strong>Telefone:</strong> (11) 99999-9999</li>
            </ul>

            <h2>Experiência Profissional</h2>
            <ul>
                <li><strong>Empresa:</strong> BBC NEWS</li>
                <li><strong>Cargo:</strong> Desenvolvedor de Software</li>
                <li><strong>Período:</strong> Jan 2024 - Mai 2026</li>
            </ul>

            <h2>Endereço</h2>
            <ul>
                <li><strong>CEP:</strong> 33444111</li>
                <li><strong>Rua:</strong> Jacinto</li>
                <li><strong>Cidade:</strong> BH</li>
                <li><strong>Estado:</strong> MG</li>
            </ul>

            <h2>Escolaridade</h2>
            <ul>
                <li><strong>Escola:</strong> Cotemig</li>
                <li><strong>Unidade:</strong> Cotemig Barroca</li>
                <li><strong>Ensino:</strong> 3 ano Ensino medio</li>
            </ul>
        </body>
        </html>
    '''

if __name__ == '__main__':
    app.run(debug=True)
