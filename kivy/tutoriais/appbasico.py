import kivy
from kivy.app import App
from kivy.uix.button import Button
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.label import Label


class BasicApp(App):
    """
    Aplicativo Básico Kivy
    """
    def build(self):
        """
        Construir o Aplicativo
        """
        layout = BoxLayout(orientation='vertical')
        lb = Label(text='Label 1')
        bt = Button(text='Botão1')
        layout.add_widget(bt)
        layout.add_widget(lb)
        layout2 = BoxLayout(orientation='horizontal')
        lb2 = Label(text='Label2')
        lb3 = Label(text='Label3')
        layout2.add_widget(lb2)
        layout2.add_widget(lb3)
        layout.add_widget(layout2)

        return layout


if __name__ == '__main__':
    BasicApp().run()
