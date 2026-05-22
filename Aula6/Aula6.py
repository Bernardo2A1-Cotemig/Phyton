from flask import Flask, request, render_template_string

app = Flask(__name__)


def mostra_login():
    return render_template_string("""
    <h2>Login</h2>
    <form method="POST">
        <input type="text" name="usuario" placeholder="Usuário"><br><br>
        <input type="password" name="senha" placeholder="Senha"><br><br>
        <button type="submit">Entrar</button>
    </form>
    """)


def faz_login():
    usuarioDigitado = request.form.get('usuario')
    senha = request.form.get('senha')

    usuariosAutorizados = [
        {"nome": "janaina", "senha": "1234"},
        {"nome": "marcos", "senha": "1234"}
    ]

    for usuario in usuariosAutorizados:
        if usuario["nome"] == usuarioDigitado and usuario["senha"] == senha:
            return "<h1>Acesso autorizado</h1>"

    return "<h1>Login inválido</h1>"


@app.route('/', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        return faz_login()
    else:
        return mostra_login()


if __name__ == "__main__":
    app.run(debug=True)