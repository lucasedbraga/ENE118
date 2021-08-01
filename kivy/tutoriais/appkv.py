import kivy
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label


class MyWidget(BoxLayout):

    def incrementar(self):
        self.ids['lb'].text = str(int(self.ids['lb'].text)+1)


class BasicApp(App):
    """
    Aplicativo Básico Kivy
    """
    def build(self):
        """
        Construir o Aplicativo
        """
        return MyWidget()


if __name__ == '__main__':
    BasicApp().run()
