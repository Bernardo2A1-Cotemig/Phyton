from flask import Flask

app = Flask(__name__)  # inicio o flask


@app.route(
    "/"
)  # Isso é o decorator, ele é usado para mapear a função abaixo para a rota '/'
def helloWord():
    return "Hello Wordp"


@app.route(
    "/"
)  # Isso é o decorator, ele é usado para mapear a função abaixo para a rota '/'
def decorate():
    return "Um decorator (decorador) no Flask é uma ferramenta baseada em Python, identificada pelo símbolo @, utilizada para estender ou alterar o comportamento de funções específicas, geralmente sem modificar o código original da função. No contexto do Flask, eles são fundamentais para vincular URLs a funções de visualização (view functions)."


if __name__ == "__main__":
    app.run(
        debug=True
    )  # Isso inicia o servidor Flask em modo de depuração, o que é útil para desenvolvimento
